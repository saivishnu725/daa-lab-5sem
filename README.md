# DAA(Design and Analysis of Algorithms) lab 5sem

All the lab programs from the 5sem syllabus. They are my versions of the program because original ones suck big time.

## Requirements

1. C Compiler (preferably gcc)
2. bash shell

## Usage

1. Clone the repository

   ```bash
       git clone https://github.com/saivishnu725/daa-lab-5sem.git
       cd daa-lab-5sem/
   ```

2. a. Use this function to view/run the code

   ```bash
	  c () {
				filename=$1
				name=$(onlyname $filename)
				$EDITOR $filename
				gcc -o $name $filename
				./$name
		}

		cr () {
				filename=$1
				name=$(onlyname $filename)
				gcc -o $name $filename
				./$name
		}
   ```

	 b. Example
	 ```bash
	 #view the code in your editor and run it on exit
	 c filename.c

	 # run the code directly without viewing it
	 cr filename.c
	 ```

## License

[GNU General Public License v2.0](https://choosealicense.com/licenses/gpl-2.0/)

## Program list

Part A:
1. Selection Sort
2. 0/1 Knapsack
3. Min & Max values
4. Quick Sort

Part B:
1. Adjacency Matrix of a Graph
2. Sum of Subsets
3. Job Sequencing
4. Optimal Binary Search Tree
