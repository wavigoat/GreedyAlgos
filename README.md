# GreedyAlgos

Name: Kaitlyn Tran  
UFID: 79518935  

Name: May Macler  
UFID: 26170596  

## Files
main.cpp: The source code for algorithms
example.txt: An example input file for the program created by main.cpp

## Compiling
To compile the matcher, use a C++ compiler (like g++):  
```
g++ -std=c++11 -o test ./src/main.cpp
```
To test with input, run:  
```
./test ./tests/example.txt
```

## Questions
### 1. Empirical Comparison
Up to 50 unique requests:
| Input File   | k  |  m  | FIFO | LRU | OPTFF |
| ------------ | -- | --- | ---- | --- | ----- |
| 10_100_A.txt | 10 | 100 |  75  | 77  |  52   |
| 10_100_B.txt | 10 | 100 |  74  | 70  |  49   |
| 10_100_C.txt | 10 | 100 |  76  | 74  |  52   |
| 10_100_D.txt | 10 | 100 |  73  | 70  |  48   |
| 10_100_E.txt | 10 | 100 |  80  | 80  |  54   |

Up to 20 unique requests:
| Input File   | k  |  m  | FIFO | LRU | OPTFF |
| ------------ | -- | --- | ---- | --- | ----- |
| 10_100_F.txt | 10 | 100 |  52  | 46  |  30   |
| 10_100_G.txt | 10 | 100 |  54  | 48  |  30   |
| 10_100_H.txt | 10 | 100 |  38  | 35  |  24   |
| 10_100_I.txt | 10 | 100 |  43  | 41  |  26   |
| 10_100_J.txt | 10 | 100 |  47  | 49  |  26   |

(Input file paths given relative to `tests/`)

Across all cases, OPTFF had significantly fewer misses than did FIFO and LRU. Although LRU seemed to perform a little better than FIFO, the difference between the two was small, and FIFO still outperformed LRU in some cases.

