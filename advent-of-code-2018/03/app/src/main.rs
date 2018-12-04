extern crate regex;

use std::collections::HashMap;
use std::error::Error;
use std::io;
use std::io::prelude::*;
use std::result;

use regex::Regex;

macro_rules! err {
    ($($tt:tt)*) => { Err(Box::<Error>::from(format!($($tt)*))) }
}

type Result<T> = result::Result<T, Box<Error>>;
type Grid = HashMap<(u32, u32), u32>;

#[derive(Debug)]
struct Point {
    x: u32,
    y: u32,
}

#[derive(Debug)]
struct Claim {
    id: u32,
    x: u32,
    y: u32,
    width: u32,
    height: u32,
}

fn parse_claim_from_string(s: &str) -> Result<Claim> {
    let input_re: Regex = Regex::new(
        r"(?x)
                \#
                (?P<id>[0-9]+)
                \s+@\s+
                (?P<x>[0-9]+),(?P<y>[0-9]+):
                \s+
                (?P<width>[0-9]+)x(?P<height>[0-9]+)
            ",
    )
    .unwrap();

    let captures = match input_re.captures(s) {
        None => return err!("Unrecognized claim format"),
        Some(captures) => captures,
    };

    Ok(Claim {
        id: captures["id"].parse()?,
        x: captures["x"].parse()?,
        y: captures["y"].parse()?,
        width: captures["width"].parse()?,
        height: captures["height"].parse()?,
    })
}

// Returns the indices of all points lying within the claim
fn points_for_claim(c: &Claim) -> Vec<Point> {
    let mut points: Vec<Point> = vec![];

    for x in c.x..(c.x + c.width) {
        for y in c.y..(c.y + c.height) {
            points.push(Point { x: x, y: y })
        }
    }

    points
}

// we need to find the total square inch coverage of all contested areas in the
// grid, because of our representation, a contested area is a index of our grid
// where the cell has a value greater than 1.
fn part1(grid: &Grid) -> u32 {
    grid.values().filter(|&&c| c > 1).count() as u32
}

// we need to find the id of the only claim that is not contested. because of
// our representation, this claim would need to have none of its points contested.
// so we iterate through all claims and check if the indices of all points in
// the claim is equal to 1.
fn part2(claims: &Vec<Claim>, grid: &Grid) -> Result<u32> {
    for claim in claims {
        if points_for_claim(&claim)
            .into_iter()
            .all(|p| grid[&(p.x, p.y)] == 1)
        {
            return Ok(claim.id);
        }
    }

    err!("No uncontested claim found")
}

fn main() -> Result<()> {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input)?;

    let mut claims: Vec<Claim> = vec![];
    for line in input.lines() {
        let claim = parse_claim_from_string(&line)?;
        claims.push(claim);
    }

    // we're working with a normal integer grid, so we can represent each square
    // inch of occupied space on the grid as an occupied square in a 2d
    // array. each time we get a claim, we calculate all the points within that
    // claim, and record those as covered in the 2d array to incrementing the
    // index of that square inch. since we dont know the range of the
    // coordinates for each claim, we're using a hashmap.

    let mut grid = Grid::new();
    for claim in &claims {
        for Point { x, y } in points_for_claim(&claim) {
            *grid.entry((x, y)).or_default() += 1;
        }
    }

    println!("part 1: {}", part1(&grid));
    println!("part 2: #{}", part2(&claims, &grid)?);

    Ok(())
}
