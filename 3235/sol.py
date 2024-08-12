from typing import List
from matplotlib import pyplot as plt
import matplotlib.patches as mpatches
import math

class Solution:
    prints = True

    def plot_circles(self, X: float, Y: float, circles: List[List[int]]) -> None:
        fig = plt.figure()
        ax = fig.add_subplot()
        ax.set_xlim([0., X*1.1])
        ax.set_ylim([0., Y*1.1])
        #ax.set_xlim([0., 30])
        #ax.set_ylim([0., 30])
        ax.add_patch(mpatches.Rectangle((0., 0.), X, Y, ls="-", lw=2., ec="black", fc="none"))
        for circle in circles:
            ax.add_patch(mpatches.Circle((circle[0], circle[1]), circle[2], ls="-", lw=1., ec="blue", fc="none"))
        print(f"X: {X}, Y: {Y}")
        plt.show()
        return None

    def lineWithinRectangle(self, X: int, Y: int, circle1: List[int], circle2: List[int]) -> bool:
        # First, check if circles themselves are within rectangle
        if self.circleCenterWithinRectangle(X, Y, circle1) or\
            self.circleCenterWithinRectangle(X, Y, circle2):
            return True

        # Checks if the line between the centers of two circles enters the rectangle
        x1 = circle1[0]
        x2 = circle2[0]
        y1 = circle1[1]
        y2 = circle2[1]

        # Avoid division by 0
        if x2-x1 == 0:
            x1 = circle1[1]
            x2 = circle2[1]
            y1 = circle1[0]
            y2 = circle2[0]

        m = (y2-y1)/(x2-x1)
        line = lambda x: m*x+(y1-m*x1)

        if line(X) <= Y:
            return True
        return False

    def circleCenterWithinRectangle(self, X: int, Y: int, circle: List[int]) -> bool:
        # Check if a circle's center is inside the rectangle

        # Case 1: center is in the rectangle (note radius >= 1 constraint)
        if circle[0] <= X and circle[1] <= Y:
            return True

        return False

    def circleHasPartWithinRectangle(self, X: int, Y: int, circle: List[int]) -> bool:
        # Check if a circle contains a part within the rectangle
        # Unless it just barely touches top right

        # Case 1: center is in the rectangle (note radius >= 1 constraint)
        if circle[0] <= X and circle[1] <= Y:
            return True

        # Case 2: center is not in the rectangle
        # Case 2a: center is directly above the rectangle
        # NOTE: not counting circles whose circumference only touches the rectangle 
        if (circle[0] <= X) and (circle[1] > Y):
            if (circle[1] - circle[2] < Y):
                return True
            else:
                return False
        # Case 2b: center is directly to the right of the rectangle
        # NOTE: not counting circles whose circumference only touches the rectangle 
        if (circle[0] > X) and (circle[1] <= Y):
            if (circle[0] - circle[2] < X):
                return True
            else:
                return False
        # Case 2c: center is to the top right of the rectangle
        # NOTE: we *are* counting circles whose circumference touches the rectangle,
        #       since these circles prevent the line from reaching the top right corner
        if (circle[0] > X) and (circle[1] > Y):
            # Calculate distance from corner of rectangle to circle center
            dist = math.sqrt((X-circle[0])**2+(Y-circle[1])**2)
            if dist <= circle[2]:
                return True
            else:
                return False
            
        # Shouldn't be here
        raise Exception("circleHasPartWithinRectangle: Shouldn't be here.")
    
    def circleDescriptor(self, X: int, Y: int, circle: List[int]) -> str:
        # Circles: [x, y, r]
        # Assuming circle is within rectangle

        desc = ""

        # Case 1: center is in the rectangle (note radius >= 1 constraint)
        if circle[0] <= X and circle[1] <= Y:
            # Check if radius takes circumference to left wall of rectangle
            if circle[0] - circle[2] <= 0:
                desc += "L"
            # Check if radius takes circumference to right wall of rectangle
            if circle[0] + circle[2] >= X:
                desc += "R"
            # Check if radius takes circumference to bottom wall of rectangle
            if circle[1] - circle[2] <= 0:
                desc += "B"
            # Check if radius takes circumference to top wall of rectangle
            if circle[1] + circle[2] >= Y:
                desc += "T"
            return desc

        # Case 2: center is not in the rectangle
        # Case 2a: center is directly above the rectangle
        if (circle[0] <= X) and (circle[1] > Y):
            # Circle should touch top by default
            desc += "T"
            # Calculate distance to each corner
            dist_tr = math.sqrt((X-circle[0])**2+(Y-circle[1])**2)
            dist_tl = math.sqrt((0-circle[0])**2+(Y-circle[1])**2)
            dist_bl = math.sqrt((0-circle[0])**2+(0-circle[1])**2)
            dist_br = math.sqrt((X-circle[0])**2+(0-circle[1])**2)
            if dist_tr <= circle[2]:
                desc += "TR"
            if dist_tl <= circle[2]:
                desc += "TL"
            if dist_br <= circle[2]:
                desc += "BR"
            if dist_bl <= circle[2]:
                desc += "BL"
            # Have unique characters in string
            ''.join(set(desc)) 
            return desc
        # Case 2b: center is directly to the right of the rectangle
        if (circle[0] > X) and (circle[1] <= Y):
            # Circle should right top by default
            desc += "R"
            # Calculate distance to each corner
            dist_tr = math.sqrt((X-circle[0])**2+(Y-circle[1])**2)
            dist_tl = math.sqrt((0-circle[0])**2+(Y-circle[1])**2)
            dist_bl = math.sqrt((0-circle[0])**2+(0-circle[1])**2)
            dist_br = math.sqrt((X-circle[0])**2+(0-circle[1])**2)
            if dist_tr <= circle[2]:
                desc += "TR"
            if dist_tl <= circle[2]:
                desc += "TL"
            if dist_br <= circle[2]:
                desc += "BR"
            if dist_bl <= circle[2]:
                desc += "BL"
            # Have unique characters in string
            ''.join(set(desc)) 
            return desc
        # Case 2c: center is to the top right of the rectangle
        if (circle[0] > X) and (circle[1] > Y):
            # Circle should right top right by default
            desc += "TR"
            # Calculate distance to each corner
            dist_tr = math.sqrt((X-circle[0])**2+(Y-circle[1])**2)
            dist_tl = math.sqrt((0-circle[0])**2+(Y-circle[1])**2)
            dist_bl = math.sqrt((0-circle[0])**2+(0-circle[1])**2)
            dist_br = math.sqrt((X-circle[0])**2+(0-circle[1])**2)
            if dist_tr <= circle[2]:
                desc += "TR"
            if dist_tl <= circle[2]:
                desc += "TL"
            if dist_br <= circle[2]:
                desc += "BR"
            if dist_bl <= circle[2]:
                desc += "BL"
            # Have unique characters in string
            ''.join(set(desc)) 
            return desc

        # Shouldn't be here
        raise Exception("circleDescriptor: Shouldn't be here.")

    def canReachCorner(self, X: int, Y: int, circles: List[List[int]]) -> bool:
        # Circles: [x, y, r]

        # Goal:
        # Check if there is a collection of circles overlapping that touch either:
        # - the top and bottom wall of the rectangle (TB)
        # - the left and right wall of the rectangle (LR)
        # - the top and right wall of the rectangle (TR)
        # - the bottom and left wall of the rectangle (BL)

        # TODO: Remove
        if self.prints:
            self.plot_circles(X, Y, circles)

        # Discard duplicates
        old_circles = circles
        circles = list()
        for circle in old_circles:
            if circle not in circles:
                circles.append(circle)

        # Discard all circles not in the rectangle
        # Label which walls of the rectangle each circle touches
        new_circles = list()
        for circle in circles:
            if self.circleHasPartWithinRectangle(X, Y, circle):
                # Circle is in rectangle
                # Label each circle with the wall it touches
                # Give each circle boolean of if it has been searched through
                desc = self.circleDescriptor(X, Y, circle)
                new_circles.append((circle, desc))

                # Short circuit with circles touching both top right and bottom left
                if "T" in desc and "R" in desc:
                    return False
                if "B" in desc and "L" in desc:
                    return False
                if "T" in desc and "B" in desc:
                    return False
                if "L" in desc and "R" in desc:
                    return False

        # TODO: Remove
        # NOTE: Print all circles and the sides they touch for now
        for circle in new_circles:
            if self.prints:
                print(circle)

        # Perform BFS
        # Loop through each circle
        # Identify following paths of circles
        # - the top to the bottom wall of the rectangle (TB)
        # - the left to the right wall of the rectangle (LR)
        # - the top to the right wall of the rectangle (TR)
        # - the left to the bottom wall of the rectangle (BL)

        # BFS Notes:
        # Use FIFO for BFS and FILO for DFS
        # Mark circles as searched when added to queue
        for idx, circle in enumerate(new_circles):
            
            if 'T' in circle[1] or 'L' in circle[1]:
                # Search for a bottom or right touching circle
                search_str = "BR"
                val = self.BFS_helper(X, Y, new_circles, circle, idx, search_str) 
                if val == True:
                    return False

        return True

    # Initiates BFS
    def BFS_helper(self, X, Y, new_circles, circle, idx, search_str):
        # new_circles: list of all valid circles
        # circle: circle we are starting BFS on
        # idx: index of circle in new_circles
        # search_str: characters to look for in a circle

        # TODO: Remove
        if self.prints:
            print()
            print(f"Starting BFS for \"{search_str}\"")
            print(f"First circle:", circle)
            print()

        # Create Queue for BFS
        # NOTE: Necessarily the first circle can't be both "TB" "TR" "LR" or "BL"
        queue = list()
        # Create new list showing which circles have been searched through
        searched = [False]*len(new_circles)
        # Mark current circle as searched
        searched[idx] = True

        # Perform BFS
        val = self.BFS(X, Y, new_circles, circle, search_str, queue, searched)

        if self.prints:
            print("Done with BFS")
        return val

    # Return TRUE if circles cause a line not to touch both corners
    def BFS(self, X, Y, new_circles, cur_circle, search_str, queue, searched):
        # new_circles: list of all valid circles
        # cur_circle: current circle
        # search_str: characters to look for in a circle
        # queue: queue for BFS
        # searched: booleans identifying which circle has already been searched through

        # TODO: Remove
        if self.prints:
            print(f"Checking circle", cur_circle)
            print(f"queue:", queue)
            print(f"searched:", searched)

        # Check if current circle is a finisher, else, continue BFS
        for end_char in search_str:
            if end_char in cur_circle[1]:
                if self.prints:
                    print(f"Current circle \"{cur_circle[1]}\" has end_char \'{end_char}\'")
                return True

        # Search through neighboring circles and add to queue
        for idx2, circle2 in enumerate(new_circles):
            # Add only if not searched
            if searched[idx2] is False:
                # Add neighboring circle to queue if touching
                if math.sqrt((circle2[0][0]-cur_circle[0][0])**2 + (circle2[0][1]-cur_circle[0][1])**2)\
                            <= (cur_circle[0][2]+circle2[0][2]):
                    # NOTE: Not adding if line between two circles isn't in rectangle
                    if self.lineWithinRectangle(X, Y, cur_circle[0], circle2[0]):
                        #if cur_circle[0][0] > X and circle2[0][0] > X and\
                            #cur_circle[0][1] > Y and circle2[0][1] > Y:
                        if self.prints:
                            print("Adding circle to queue", circle2)
                        queue.append(circle2)
                        searched[idx2] = True
                    else:
                        print(f"Line not within rectangle between circles:", cur_circle[0], circle2[0])
                        continue

        # Search through remaining circles
        while len(queue) > 0:
            next_circle = queue.pop(0)
            val = self.BFS(X, Y, new_circles, next_circle, search_str, queue, searched)
            if val == True:
                return True
        return False

sol = Solution()
#print(sol.canReachCorner(3,4,[[4,1,1]]))
#print(sol.canReachCorner(6,8,[[5,2,2],[3,4,1],[2,7,3]]))
#print(sol.canReachCorner(4.25,4.25,[[2.8,7,3],[7,2.8,3]]))
#print(sol.canReachCorner(15,15,[[2,20,13],[20,2,13]]))
#print(sol.canReachCorner(8,8,[[1,4,1],[3,4,1],[5,4,1],[7,4,1]]))
#print(sol.canReachCorner(5,6,[[2,1,1],[4,2,1],[4,1,1],[4,2,1],[2,4,2],[2,2,1],[4,3,1]]))
#print(sol.canReachCorner(6,8,[[5,2,2],[5,2,2],[3,4,1],[2,7,3]]))
print(sol.canReachCorner(37, 43, [[12,6,6],[35,13,2],[13,21,13],[6,39,4],[1,23,1],[31,30,6],[32,13,5]]))
