(ns main
  (:require [clojure.string :as str]))

;; TODO: implement aoc2020-02 in clojure

(defn read_input []
  (as-> (slurp "../input.in") i
    (str/split i #"\n")
    (map #(Integer/parseInt %) i)))

(defn part1 [input]
  (for [a input
        b input
        :when (< a b)
        :when (= (+ a b) 2020)]
    (list a b (* a b))))

(defn part2 [input]
  (for [a input
        b input
        c input
        :when (< a b c)
        :when (= (+ a b c) 2020)]
    (list a b c (* a b c))))

(defn three_sum
  "Quadratic solution to the 3SUM problem"
  [input n]
  (let [s (set input)]
    (for [a input
          b input
          :let [c (- n (+ a b))]
          :when (< a b c)
          :when (s c)]
      (list a b c (* a b c)))))

(let [input (read_input)]
  (println (part1 input))
  (println (part2 input))
  (println (three_sum input 2020)))

