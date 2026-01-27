class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        def get_max_consecutive(bars):
            bar_set = set(bars)
            max_len = 1
            
            for bar in bar_set:
                if bar - 1 not in bar_set:
                    current_bar = bar
                    current_len = 1
                    
                    while current_bar + 1 in bar_set:
                        current_bar += 1
                        current_len += 1
                    
                    max_len = max(max_len, current_len)
            
            return max_len + 1

        max_h_gap = get_max_consecutive(hBars)
        max_v_gap = get_max_consecutive(vBars)
        
        side = min(max_h_gap, max_v_gap)
        
        return side * side