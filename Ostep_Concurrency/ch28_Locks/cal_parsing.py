#parser -S option only
import os
import re
def parse(infile, outname):
    p = re.compile('[0-9]+[.][0-9]+')
    outfile = open("{}".format(outname),'a')
    cal = float()
    count = 0
    for line in infile: 
        nline = line
        line = line.strip()
        if 'STATS:: Emulation Rate' in line :
            if count == 5 : 
                count = 0   #New interrupt frq
                cal = cal / 5
                outfile.write(str(cal))
                outfile.write('\n')
                cal = 0.0

            count+=1
            #split here
            line = line.split()
            for chunk in line:
                if p.match(chunk):
                    cal += float(chunk)
                    #print(chunk)
    if count ==5:
        cal = cal/5
        outfile.write(str(cal))
        outfile.write('\n')
    outfile.close()


def search_currdir():
    infile = open("./i4_tts",'r')
    parse(infile,"i4_cal")
    infile.close()
    

if __name__ == '__main__':
    search_currdir()

    


