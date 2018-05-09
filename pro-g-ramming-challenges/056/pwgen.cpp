#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <vector>

#include <boost/program_options.hpp>

namespace po = boost::program_options;
using namespace std;

std::string generate_password(int length, bool use_lowercase,
                              bool use_uppercase, bool use_numbers,
                              bool use_specials) {
  auto abc = "abcdefghijklmnopqrstuvwxyz";
  auto ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  auto numbers = "012356789";
  auto specials = ",.-;:_*^!#¤%&/()=?@£$½¥{[]}±|~";

  // the problem with this is that the probability for a cell in the
  // password being a letter is higher, because there are more
  // letters, should split the probabilities equally over all enabled
  // features
  std::string values = " ";
  if (use_lowercase)
    values += abc;
  if (use_uppercase)
    values += ABC;
  if (use_numbers)
    values += numbers;
  if (use_specials)
    values += specials;

  // another thing of note, the randomness we use is not
  // cryptographically secure

  random_shuffle(values.begin(), values.end());

  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<> dist(0, values.length());

  std::string pw = "";

  for (int i = 0; i < length; i++) {
    pw += values[dist(rng)];
  }

  return pw;
}

int main(int argc, char *argv[]) {
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help,h", "produce help message")
    ("length,l", po::value<int>()->default_value(8), "length of password")
    ("lowercase,L", "use lowercase letters")
    ("uppercase,U", "use uppercase letters")
    ("numbers,N", "use numbers")
    ("specials,S", "use special characters");

  po::variables_map vm;
  try {
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
  } catch (po::error &e) {
    cout << "Error parsing arguments, try --help" << endl;
    cout << e.what() << endl;
    return 0;
  }

  if (vm.count("help")) {
    cout << desc << '\n';
    return 0;
  }

  cout << generate_password(vm["length"].as<int>(), vm.count("lowercase"),
                            vm.count("uppercase"), vm.count("numbers"),
                            vm.count("specials"))
       << '\n';
}
