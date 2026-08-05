package chessboard

// Declare a type named Rank which stores if a square is occupied by a piece - this will be a slice of bools
type Rank []bool

// Declare a type named Chessboard which contains a map of eight Ranks, accessed with keys from "A" to "H"
type Chessboard map[string]Rank

// CountInRank returns how many squares are occupied in the chessboard,
// within the given rank
func CountInRank(cb Chessboard, rank string) int {
	occupied := 0
	fullRank, validRank := cb[rank]
	if validRank {
		for _, isOccupied := range fullRank {
			if isOccupied {
				occupied++
			}
		}
	}
	return occupied
}

// CountInFile returns how many squares are occupied in the chessboard,
// within the given file
func CountInFile(cb Chessboard, file int) int {
	occupied := 0
	if 1 <= file && file <= 8 {
		for _, rank := range cb {
			if rank[file-1] {
				occupied++
			}
		}
	}
	return occupied
}

// CountAll should count how many squares are present in the chessboard
func CountAll(cb Chessboard) int {
	squares := 0
	for _, rank := range cb {
		squares += len(rank)
	}
	return squares
}

// CountOccupied returns how many squares are occupied in the chessboard
func CountOccupied(cb Chessboard) int {
	occupied := 0
	for _, rank := range cb {
		for _, isOccupied := range rank {
			if isOccupied {
				occupied++
			}
		}
	}
	return occupied
}
