import matplotlib.pyplot as plt 
  
# x axis values 
x = [200,1000,10000,100000,10**6] 
# corresponding y axis values 
y = [0.001958,0.005211,0.043403,0.490195,6.574135] 
y1=[0.004301,0.013897,0.119289 ,1.320655,17.635662]
s=[51432.0/1024,311400.0/1024,3926760.0/1024,47254248.0/1024,550834152.0/1024]
s1=[ 632.0/1024,3284.0/1024,37244.0/1024,318640.0/1024,3450696.0/1024]
# plotting the points  
# print s
# print s1

plt.plot(x, s1, color='green', linestyle='dashed', linewidth = 2, 
         marker='o', markerfacecolor='red', markersize=6 ,label = "navie") 
plt.plot(x, s, color='green', linestyle='dashed', linewidth = 2, 
         marker='o', markerfacecolor='blue', markersize=6,label="presistent-segement-tree") 

# naming the x axis 
plt.xlabel('size of array ') 
# naming the y axis 
plt.ylabel('space in mb ') 
  
# giving a title to my graph 
plt.title('size of array v/s space in mb graph') 
  
# function to show the plot 
plt.show() 
