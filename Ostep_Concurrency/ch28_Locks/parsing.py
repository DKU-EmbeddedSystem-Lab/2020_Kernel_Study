#parser -S option only
import os
import re
def parse(infile, outname):
    outfile = open("{}".format(outname),'w')
    for line in infile: 
        nline = line
        line = line.strip()
        if 'ARG' in line :
            outfile.write(nline)
        elif 'STATS::' in line :
            outfile.write(nline)

    outfile.close()


def search_currdir():
    infile = open("./csv1/i32_1",'r')
    parse(infile,"i32_tts")
    infile.close()
    

if __name__ == '__main__':
    search_currdir()

    


