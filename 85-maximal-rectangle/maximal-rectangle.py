class Solution(object):
    def maximalRectangle(self, matrix):
        if not matrix or not matrix[0]:
            return 0
        
        rows = len(matrix)
        cols = len(matrix[0])
        
        heights = [0] * cols
        maxArea = 0
        
        for i in range(rows):
            # Build histogram
            for j in range(cols):
                if matrix[i][j] == '1':
                    heights[j] += 1
                else:
                    heights[j] = 0
            
            # Largest Rectangle in Histogram
            stack = []
            for k in range(cols + 1):
                cur = heights[k] if k < cols else 0
                
                while stack and cur < heights[stack[-1]]:
                    h = heights[stack.pop()]
                    w = k if not stack else k - stack[-1] - 1
                    maxArea = max(maxArea, h * w)
                
                stack.append(k)
        
        return maxArea
