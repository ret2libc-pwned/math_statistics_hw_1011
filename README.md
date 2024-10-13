# math_statistics_hw_1011

## Introduction (simplified)

A tool for single-variable statistics data analysis with a `.txt` input, which can output mean ($\mu$), median, variance ($s^2$), modes and a table of distribution into a `.csv` file.

## Introduction

A simple tool to tackle with textbook problems like this:

> A medical research team, in order to study the effectiveness of a new lipid-lowering drug, gave the drug to 50 patients, and after one week the LDL levels (in mmol/L) were measured as follows.
> The LDL levels (in mmol/L) measured after one week are as follows:
>
> ```
> 2.80 3.54 3.02 3.43 3.69 2.46 3.03 3.06 3.35 3.57
> 3.72 4.36 2.56 4.11 2.81 2.77 5.32 3.34 3.68 3.95
> 2.98 3.63 3.65 3.22 3.90 3.97 3.86 3.93 3.17 3.72
> 3.36 3.56 3.80 4.57 5.02 3.31 3.52 3.27 3.98 4.72
> 3.03 4.09 2.14 2.06 3.00 2.75 3.84 2.16 3.09 2.81
> ```
>
> a) Make a frequency distribution table.
>
> b) Plotting frequency distribution histograms and frequency distribution line graphs.

By just grabbing the dataset from the textbook using OCR into a `.txt` file, no matter the data is split by space or tab or newline, and start the tool, a `.csv` file is generated automatically like this:

> Mean: 3.4536, Median: 3.915, variance ($s^2$): 0.0097, Mode: {3.0300, 3.7200, 2.8100} 
>
> | #    | Interval             | Count | Freq | Datas                                                        |
> | ---- | -------------------- | ----- | ---- | ------------------------------------------------------------ |
> | 0    | [2.000000, 2.444444) | 3     | 0.06 | 2.0600 2.1400 2.1600                                         |
> | 1    | [2.444444, 2.888889) | 7     | 0.14 | 2.4600 2.5600 2.7500 2.7700 2.8000 2.8100 2.8100             |
> | 2    | [2.888889, 3.333333) | 11    | 0.22 | 2.9800 3.0000 3.0200 3.0300 3.0300 3.0600 3.0900 3.1700 3.2200 3.2700  3.3100 |
> | 3    | [3.333333, 3.777778) | 14    | 0.28 | 3.3400 3.3500 3.3600 3.4300 3.5200 3.5400 3.5600 3.5700 3.6300 3.6500  3.6800 3.6900 3.7200 3.7200 |
> | 4    | [3.777778, 4.222222) | 10    | 0.2  | 3.8000 3.8400 3.8600 3.9000 3.9300 3.9500 3.9700 3.9800 4.0900  4.1100 |
> | 5    | [4.222222, 4.666667) | 2     | 0.04 | 4.3600 4.5700                                                |
> | 6    | [4.666667, 5.111111) | 2     | 0.04 | 4.7200 5.0200                                                |
> | 7    | [5.111111, 5.555556) | 1     | 0.02 | 5.32                                                         |
> | 8    | [5.555556, 6.000000) | 0     | 0    |                                                              |

Or you may say, where is the histogram and line graph?

Of course, you can use spreadsheet software like Excel to draw your desired graph. But alternatively, by turning the screen $\pi / 2$ left,  the *shape* of the `Datas` column already looks like a *real* histogram, thanks to the aligned output format with 4 decimal points. If you want a line graph, just sketch that out based on the *histogram*!

## Usage

Download latest binary executable from Releases page.

Put your `.txt` input at the same directory as the binary executable.

Start your terminal and switch to the directory, start analyzing the data by

```cmd
math_statistics_hw_1011.exe <filename>
```

You can drag the file into the terminal to quickly fill in the `<filename>` parameter.

If you don't indicate the `<filename>`, the program will find the file `data` and attempt to analyze it.

The result file is `<filename>_result.csv`.
