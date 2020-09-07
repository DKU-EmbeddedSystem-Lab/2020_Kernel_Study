def reader(infile, fname):
    i = int()
    count = int()
    f = open("{}".format(fname),'w');
    for line in infile:
        line.strip()
        i+=1
        if 'read' in line:
            if count == 0 :
                row = "w {0} {1}  s\n".format(i,count)
                f.write(row)
            count+=1;
        else:
            if count != 0:
                row = "w {0} {1} e\n".format(i,count)
                f.write(row)
                count = 0

    f.close()


if __name__ == "__main__":
    n = "1.txt"
    f = open("%s"%n,'r')
    reader(f,n+"123")    
    f.close()
