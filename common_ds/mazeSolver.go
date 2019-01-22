package main

// Maze solver with backtracking
// Author: Angelo Poerio <angelo.poerio@gmail.com>

import "fmt"

const (
	EMPTY = 'E'
	WALL = 'W'
	PATH = '*'
)

func printMaze(maze [][]byte) {
	for i := 0; i < len(maze);i++ {
		fmt.Println(string(maze[i]))
	}
}

func isValid(x int, y int, mazeSize int) bool {
	x_valid := x >= 0 && x < mazeSize
	y_valid := y >= 0 && y < mazeSize
	return x_valid && y_valid
}

func solveMaze(maze [][]byte, x int, y int) bool {
	mazeSize := len(maze)
	
	if x == mazeSize-1 && y == mazeSize-1 {
		maze[x][y] = PATH
		return true
	}

	if isValid(x,y,mazeSize) && maze[x][y] == EMPTY {
		maze[x][y] = PATH
		if solveMaze(maze,x+1,y) {
			return true
		}
		if solveMaze(maze,x,y+1) {
			return true
		}
		if solveMaze(maze,x+1,y+1) {
			return true
		}
		
		maze[x][y] = EMPTY // backtrack	
		return false
	}

	return false
}

func main() {
	testMaze := [][]byte {
		[]byte{EMPTY,WALL,WALL,WALL},
		[]byte{EMPTY,WALL,WALL,WALL},
		[]byte{EMPTY,EMPTY,EMPTY,WALL},
		[]byte{EMPTY,WALL,EMPTY,EMPTY}, // switch the last element from EMPTY to WALL to make it not solvable 
	}
	
	printMaze(testMaze)
	is_solvable := solveMaze(testMaze,0,0)
	fmt.Println("<------- SOLUTION -------->\n")
	fmt.Printf("Is Solvable: %b\n", is_solvable)
	printMaze(testMaze)
}

