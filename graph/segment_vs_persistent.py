import matplotlib.pyplot as plt 
  
# x axis values 
x = [10,50,100,500,1000,5000] 
# corresponding y axis values 
y = [0.008414,0.009445,0.012028,0.0442206,0.044017,0.053172] 
y1=[0.044289,0.063789,0.1134489,0.504911,0.957499,4.730650]
s=[483456.0/1024,497160.0/1024,514416.0/1024,652896.0/1024,824880.0/1024,2204208.0/1024]
s1=[5279736.0/1024,24478776.0/1024,48477576.0/1024,240467976.0/1024,480455976.0/1024,2400359976.0/1024]
# plotting the points   
# print s
# print s1
plt.plot(x, s1, color='green', linestyle='dashed', linewidth = 2, 
         marker='o', markerfacecolor='red', markersize=6 ,label = "segment-tree") 
plt.plot(x, s, color='green', linestyle='dashed', linewidth = 2, 
         marker='o', markerfacecolor='blue', markersize=6,label="presistent-segement-tree") 

# naming the x axis 
plt.xlabel('number of query ') 
# naming the y axis 
plt.ylabel('space in mb') 
  
# giving a title to my graph 
plt.title('query v/s space graph') 
  
# function to show the plot 
plt.show() 
