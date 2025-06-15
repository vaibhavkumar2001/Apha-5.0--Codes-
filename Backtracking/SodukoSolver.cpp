#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool isSafe(char digit,int row,int col,vector<vector<char>>& board) {
        //row pe check karoonga
        //col check 
        //3 * 3 pe check 
        //ab main row pe check karoonga
        int n = board.size();
        for(int k = 0;k < n;k++) {
            if(board[row][k] == digit) {
                //Same digit pehle se hi exists krta h 
                return false;
            }
        }
        //col check 
        for(int k = 0;k < n;k++) {
            if(board[k][col] == digit) {
                return false;
            }
        }
        //3 * 3 pe check 
        for(int k = 0;k < n;k++) {
            if(board[3 *(row/3) + k/3] [3 * (col/3) + k % 3] == digit) {

                return false;
            }
        }
        return true;
    }
    bool Solve(vector<vector<char>>& board) {
        //mujhe hr ek row pe traverse krna h ki main number ko place kr skta hoon ki nhi 
        //toh main 2D array pe do loops se traverse kr skta hoon 
        for(int i = 0;i < board.size();i++) {
            for(int j = 0;j < board[0].size();j++) {
                if(board[i][j] == '.') {
                    //agr board pe jo i or j  h agr woh . yeh h toh tbhi main 1-9 tk rakh skta hoon
                    //digit rakhne ke liye loop chalaoonga
                    for(char digit = '1';digit <= '9';digit++) {
                        //aur hm uss digit ko tbhi rakh skte h tbhi ki woh digit safe ho 
                        if(isSafe(digit,i,j,board) == true) {
                            board[i][j] = digit;//ab aage ka answer recursion leke aayega 
                            //ab yeh jo recursion solve krke la ha h woh yeh bhi toh batayega ki main saare number ko rakh paya ki nahi toh mujhe yeh variable bana ke usme store krna padega
                           bool RecursionKaAns = Solve(board);
                           if(RecursionKaAns == true) {
                            return true;
                           }
                           else {
                            //agr false aata h toh mujhe bactrack krke wapas se peehe wale box pe number ko rakhna padega
                            board[i][j] = '.';
                           }
                        }
                    }
                    //agr main yahan tk pachooch gaya hoon toh main koi bhi digit nhi rakh paya hoon
                    return false;
                }
            }
        }
        //agr main yaha tk pachooch gaya hoon toh main saare digit ko place kr chuka hoon mera ans true hoga 
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        Solve(board);
    }
};