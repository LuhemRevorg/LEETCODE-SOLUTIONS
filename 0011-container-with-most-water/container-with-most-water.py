class Solution:
    def maxArea(self, height: List[int]) -> int:
        left_pos = 0
        right_pos = len(height) - 1
        move_left = True
        max_area = 0
        max_height = 0

        while(left_pos < right_pos):
            h = min(height[left_pos], height[right_pos])
            if max_height < h:
                area = (right_pos-left_pos)*h
                max_height = h
                if max_area < area:
                    max_area = area

            if height[right_pos] > height[left_pos]:
                left_pos+=1
            else:
                right_pos -=1
        
        return max_area
