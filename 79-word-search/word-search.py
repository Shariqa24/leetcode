from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        x = len(word)
        rows = len(board)
        cols = len(board[0])
        
        def solve(r, c, i):
            if i == x:
                return True       
            
            if (r < 0 or r >= rows or 
                c < 0 or c >= cols or
                board[r][c] != word[i]):
                return False
                
            ch = board[r][c]
            board[r][c] = "#"
            
            found = (
                solve(r + 1, c, i + 1) or 
                solve(r - 1, c, i + 1) or 
                solve(r, c + 1, i + 1) or 
                solve(r, c - 1, i + 1)
            )
            
            board[r][c] = ch
            return found
            
        for r in range(rows):
            for c in range(cols):
                if solve(r, c, 0):
                    return True
        return False
