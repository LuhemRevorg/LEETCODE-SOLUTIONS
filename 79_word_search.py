class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        def explore(i, j, at):
            if i < 0 or i > len(board) - 1 or j < 0 or j > len(board[0]) - 1:
                return False
            if board[i][j] == word[at] and at==len(word) - 1:
                return True
            elif board[i][j] == word[at]:
                tmp = board[i][j]
                board[i][j]="*" 
                f = explore(i, j+1, at+1) or explore(i+1,j,at+1) or explore(i,j-1,at+1) or explore(i-1,j,at+1)
                board[i][j] = tmp
                return f
            else:
                return False
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if explore(i, j, 0):
                    return True
                

        return False
        

                

    
        