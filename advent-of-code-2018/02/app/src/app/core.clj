(ns app.core
  (:require [clojure.string :as str])
  (:gen-class))

(defn- n-occurances [string n]
  "Returns true if any character occurs n times in string."
  (let* [chars (seq string)
         freqs (frequencies chars)
         values (vals freqs)
         set (apply hash-set values)]
    (contains? set n)))
;; (n-occurances "test" 2)

(defn- part1 [input]
  "Multiply the number of strings where a character occur either 2 or 3 times."
  (let [twoos (count (filter #(n-occurances % 2) input))
        threes (count (filter #(n-occurances % 3) input))]
    (* twoos threes)))

(defn- hamming-distance [s1 s2]
  "Calculate the hamming-distance (edit distance) between two strings."
  (->> (map = s1 s2)
       (remove true?)
       (count)))
;; (hamming-distance "test" "tasb")

(defn- first-of-distance-1 [coll]
  "Find first pair of strings with a hamming-distance of 1 in a collection"
  (loop [ln coll]
    (let* [myfn (partial #'hamming-distance (first ln))
           distances (map myfn (rest ln))
           myseq (vec distances)]
      (cond
        (empty? myseq) nil
        (some #(= 1 %) myseq) ;; return pair of strings with a edit-distance of 1
        [(first ln) (second (flatten (filter #(= 1 (first %)) (map vector myseq (rest ln)))))]
        :else (recur (rest ln))))))

(defn- equal-part [s1 s2]
  "Returns the equal parts of two strings."
  (let* [loc (map = s1 s2) ;; find all locations where characters are equal
         pairs (map vector s1 loc) ;; pair up with locations
         equals (filter #(true? (second %)) pairs) ;; remove un-equal chars
         implode (map first equals)] ;; grab chars from pair
    (apply str implode))) ;; convert to string

;; (equal-part "test" "tast")

(defn- part2 [input]
  (let [[s1 s2] (first-of-distance-1 input)]
    (equal-part s1 s2)))

(let [ln (line-seq (java.io.BufferedReader. *in*))]
  (println "part 1: " (part1 ln))
  (println "part 2: " (part2 ln)))

(System/exit 0)
