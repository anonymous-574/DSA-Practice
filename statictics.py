from math import sqrt
from scipy import stats

def average(l):
    avg=0;
    for num in l:
        avg+=num
    avg=avg/len(l)
    return avg
    
def median(l):
    l1=sorted(l)
    length = len(l1)
    median=0
    if length%2==0:
        median = (l1[length//2]+l1[(length//2)+1])/2
    else:
        median=l1[(length+1)//2]
    return median
    
def quartiles(l,pieces):
    l1=sorted(l)
    length = len(l1)
    median=0
    if length%2==0:
        median = (l1[length//2]+l1[(length//2)+1])/2
    else:
        median=l1[(length+1)//2]
    print(f"{median}")
    
def variance(l):
    #original
    mean = average(l)
    for num in l:
        num=num-mean
        num=num*num
    variance=average(l)
    return variance

def std_deviation(l):
    variance = variance(l)
    return sqrt(variance)

def trimmed_mean(l,percentage):
    return stats.trim_mean(l,percentage/100)
  

    
numbers=[1,2,4,5,3,5,3]
#average(numbers)
median(numbers)

