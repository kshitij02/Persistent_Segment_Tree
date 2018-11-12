import matplotlib.pyplot as plt 
  
# x axis values 
x = [10,100,1000,10000,100000] 
# corresponding y axis values 
y = [0.513133,0.505762,0.513299,0.570361,1.099634] 
y1=[0.274032,1.528225,14.128664, 139.143845,1386.652832]
s=[47758248/1024,47758248/1024,47758248/1024,47758248/1024,47758248/1024]
s1=[325348/1024, 362144/1024,375332/1024,396276/1024,402088/1024]
# plotting the points  
plt.plot(x, s1, color='green', linestyle='dashed', linewidth = 2, 
         marker='o', markerfacecolor='red', markersize=6 ,label = "navie") 
plt.plot(x, s, color='green', linestyle='dashed', linewidth = 2, 
         marker='o', markerfacecolor='blue', markersize=6,label="presistent-segement-tree") 

# naming the x axis 
plt.xlabel('queries ') 
# naming the y axis 
plt.ylabel('space in mb ') 
  
# giving a title to my graph 
plt.title('query v/s space graph') 
  
# function to show the plot 
plt.show() 
