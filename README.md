### Overview

This program, **clean**, is a command-line utility designed to process two-dimensional grids of floating-point numbers for machine learning purposes by replacing or removing bad values (`nan`). It uses **standard input** for data ingestion and **standard output** for cleaned data output. The program is modular, efficient, and handles grids of any size.

---

## Features

- **Imputation Strategy (Default)**: Replaces `nan` values with the average of the legal values in the same column. If all values in a column are `nan`, they are replaced with `0.0`.
- **Deletion Strategy**: Removes rows containing `nan` values.
- Reads input and outputs data in a compact format.
- Handles both small and large datasets efficiently.
- Uses a modular structure split across multiple `.c` files.

---

## Usage

The utility can be invoked using the following syntax:
clean [-d]

- **Without Flags**: Cleans the data using the **imputation strategy**.
- **`-d` Flag**: Cleans the data using the **deletion strategy**.

### Input Format

The input must be a whitespace-separated list of numbers:
1. The first two numbers represent the **number of rows (R)** and **number of columns (C)**.
2. The next `R * C` values represent the data grid.

### Output Format

- The cleaned data is output as a grid, maintaining the original dimensions (for imputation) or updated dimensions (for deletion).
- Each float is rounded to **3 decimal places**.

---

## Example Usage

### Imputation Strategy (Default)

Input (`bad_data.txt`): 3 4 nan nan 5.3 1.0 nan 1.8 1.9 nan nan 2.8 nan nan
Command: clean <bad_data.txt >cleaned_data.txt
Output (`cleaned_data.txt`): 3 4 0.000 2.300 5.300 1.000 0.000 1.800 1.900 1.000 0.000 2.800 3.600 1.000

### Deletion Strategy

Input (`bad_data2.txt`): 4 4 nan nan 5.3 1.0 1.0 1.8 1.9 2.3 nan 2.8 nan nan 0.0 1.2 3.4 5.6
Command: clean -d <bad_data2.txt >cleaned_data.txt
Output (`cleaned_data.txt`): 2 4 1.000 1.800 1.900 2.300 0.000 1.200 3.400 5.600

## Installation
1. Clone the repository
2. Navigate to the project directory and build the program using the provided Makefile:
make
