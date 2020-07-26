#include<stdio.h>
  
  int jumpcount(int x, int y, int n, int height[])
  {
     int jumps = 0;
  
      for (int i = 0; i < n; i++) {
          if (height[i] <= x) {
              jumps++;
              continue;
          }
  
          /* If height of wall is greater than 
            up move */
          int h = height[i];
         while (h > x)
          {
              jumps++;
              h = h - (x - y);
          }
          jumps++;
      }
      return jumps;
} 
  int main()
  {
     int up,down,n_wall;
     scanf("%d %d %d",&up,&down,&n_wall);
  
  
      int height[n_wall];
      int i;
      for(i=0;i<n_wall;i++)
      scanf("%d",&height[i]);
      printf("%d\n",jumpcount(up, down, n_wall, height));
      return 0;
  }
