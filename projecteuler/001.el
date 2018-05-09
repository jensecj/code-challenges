(setq sum 0)

(defun mult_of_3_or_5 (x)
  (if (or (= 0 (% x 3)) (= 0 (% x 5)))
      (setq sum (+ sum x))
    0))

(mapcar 'mult_of_3_or_5 (number-sequence 1 999))

(print sum)
