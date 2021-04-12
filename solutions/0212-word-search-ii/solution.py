class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:

        def dfs(row, col, keyWord):
            if len(keyWord) == 0:
                return True
            if (row, col) in visited or row < 0 or row >= nrows or col < 0 or col >= ncols:
                return False
            if board[row][col] == keyWord[0]:
                visited.add((row,col))
                return dfs(row-1, col, keyWord[1:]) or dfs(row+1, col, keyWord[1:]) or dfs(row, col-1, keyWord[1:]) or dfs(row, col+1, keyWord[1:])
            else:
                return False

        nrows  = len(board)
        ncols  = len(board[0])
        result = []
        charTable = collections.defaultdict(list)
        visited = set()

        # Prepare a hash table to hold positions of each character
        for i in range(nrows):
            for j in range(ncols):
                charTable[board[i][j]].append((i, j))

        for word in words:
            #if all(ch in charTable for ch in word):
            if word[0] in charTable:
                for row, col in charTable[word[0]]:
                    visited.clear()
                    if dfs(row, col, word):
                        result.append(word)
                        break

        return result

