from matplotlib import pyplot as plt

def reader(infile):
    #, fname):
    i = int()
    i =0
    count = int()
    mask = [0 for i in range(100000)]
    #f = open("{}".format(fname),'w');
    for line in infile:
        line.strip()
        #Job
        if 'write' in line :
            mask[i] = 1   
        i+=1
    #f.close()
    mask = mask[0:i]
    print(mask)
    #return f

#def writer(infile):
    #mask = list(1000000)
    #for line in infile:
        #line.strip()
        #line = line.split()
        #while True:
            #TASK
            #if #condition :
                #break
            



if __name__ == "__main__":
    n = "no5.txt"
    f = open("%s"%n,'r')
    reader(f)    
    f.close()



