class Solution:
    def _solve(self,tiles:str,s:set,word:str) -> None:
        s.add(word)
        tiles_copy = tiles
        for i in range(0,len(tiles_copy)):
            tiles = tiles[:i] + tiles[i+1:]
            self._solve(tiles,s,word+tiles_copy[i])
            tiles = tiles_copy

    def numTilePossibilities(self, tiles: str) -> int:
        s = set()
        self._solve(tiles,s,"")
        return len(s)-1
    


        
