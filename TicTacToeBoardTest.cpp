/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, testToggle){
	TicTacToeBoard test;

	ASSERT_EQ(test.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, testPlacePiece){
	TicTacToeBoard test;
	test.placePiece(0,0);

	ASSERT_EQ(test.placePiece(0, 0), X);
}

TEST(TicTacToeBoardTest, testPlacePieceInvalid){
	TicTacToeBoard test;

	ASSERT_EQ(test.placePiece(3, 0), Invalid);
}

TEST(TicTacToeBoardTest, testGetPiece){
	TicTacToeBoard test;
	test.placePiece(0,0);

	ASSERT_EQ(test.getPiece(0, 0), X);
}

TEST(TicTacToeBoardTest, testGetPieceInvalid){
	TicTacToeBoard test;
	test.placePiece(2,0);

	ASSERT_EQ(test.getPiece(3, 0), Invalid);
}

TEST(TicTacToeBoardTest, testGetWinner){
	TicTacToeBoard test;
	test.placePiece(0,0); //X
	test.placePiece(1,0); //O
	test.placePiece(0,1); //X
	test.placePiece(1,1); //O
	test.placePiece(0,2); //X
	ASSERT_EQ(test.getWinner(), X);
}

TEST(TicTacToeBoardTest, testGetWinnerVertical){
	TicTacToeBoard test;
	test.placePiece(0,0); //X
	test.placePiece(0,1); //O
	test.placePiece(1,0); //X
	test.placePiece(1,1); //O
	test.placePiece(2,0); //X
	ASSERT_EQ(test.getWinner(), X);
}

TEST(TicTacToeBoardTest, testGetWinnerDiagonal1){
	TicTacToeBoard test;
	test.placePiece(0,0); //X
	test.placePiece(0,1); //O
	test.placePiece(1,1); //X
	test.placePiece(1,0); //O
	test.placePiece(2,2); //X
	ASSERT_EQ(test.getWinner(), X);
}

TEST(TicTacToeBoardTest, testGetWinnerDiagonal2){
	TicTacToeBoard test;
	test.placePiece(0,2); //X
	test.placePiece(0,1); //O
	test.placePiece(1,1); //X
	test.placePiece(1,0); //O
	test.placePiece(2,0); //X
	ASSERT_EQ(test.getWinner(), X);
}

TEST(TicTacToeBoardTest, testGetWinnerBlank){
	TicTacToeBoard test;
	test.placePiece(0,0); //X
	test.placePiece(0,1); //O
	test.placePiece(0,2); //X
	test.placePiece(1,1); //O
	test.placePiece(1,2); //X
	test.placePiece(1,0); //O
	test.placePiece(2,1); //X
	test.placePiece(2,2); //O
	test.placePiece(2,0); //X
	ASSERT_EQ(test.getWinner(), Blank);
}

TEST(TicTacToeBoardTest, testPlacePieceBlank){
	TicTacToeBoard test;
	test.placePiece(0,0); //X
	test.placePiece(0,1); //O
	test.placePiece(0,2); //X
	test.placePiece(1,1); //O
	test.placePiece(1,2); //X
	test.placePiece(1,0); //O
	test.placePiece(2,1); //X
	test.placePiece(2,2); //O
	test.placePiece(2,0); //X
	ASSERT_EQ(test.placePiece(2,0), Invalid);
}

//TEST(TicTacToeBoardTest, )