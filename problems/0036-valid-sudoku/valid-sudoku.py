class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row, col, box = {}, {}, {}
        for i in range(9):
            row[i] = {}
            col[i] = {}
        for i in range(3):
            for j in range(3):
                box[(i, j)] = {}        

        def isinRow(rows, no):
            nonlocal row
            if no in row[rows]:
                return True
            row[rows][no] = True
            return False
        
        def isinCol(cols, no):
            nonlocal col
            if no in col[cols]:
                return True
            col[cols][no] = True
            return False
        def isinBox(box_key, no):
            nonlocal box
            if no in box[box_key]:
                return True
            box[box_key][no] = True
            return False
        
        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    no = int(board[i][j])
                    box_key = (i // 3, j // 3)
                    if isinRow(i, no) or isinCol(j, no) or isinBox(box_key, no):
                        return False
        
        return True
