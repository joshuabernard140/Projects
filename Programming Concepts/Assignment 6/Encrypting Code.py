# Joshua Bernard U92651625 - Driver - 50% work
# Raiyan Ali U24491765 - Navigator - 50% work

# This program will encrypt a given message into the given code.


def main():
    file = open(input('Input text file to be converted to pig latin: '), 'r') # asks for file to read
    newFileName = input('Input new file name (txt file is preferred): ') # requests name for new file
    contents = file.read() # reads given file
    encryption = ''
    for x in contents: # encrypts each character
        if x == '\n':
            encryption += '\n'
            continue
        encryption += Encrypt_Code[x]
    newFile = open(newFileName, 'w') # creates new file
    newFile.write(encryption) # writes translation to new file
    newFile.close()


# dictionary to encrypt given message
Encrypt_Code =  {'A':')','a':'0','B':'(','b':'9','C':'*','c':'8',\
        'D':'&','d':'7','E':'^','e':'6','F':'%','f':'5',\
        'G':'$','g':'4','H':'#','h':'3','I':'@','i':'2',\
        'J':'!','j':'1','K':'Z','k':'z','L':'Y','l':'y',\
        'M':'X','m':'x','N':'W','n':'w','O':'V','o':'v',\
        'P':'U','p':'u','Q':'T','q':'t','R':'S','r':'s',\
        'S':'R','s':'r','T':'Q','t':'q','U':'P','u':'p',\
        'V':'O','v':'o','W':'N','w':'n','X':'M','x':'m',\
        'Y':'L','y':'l','Z':'K','z':'k','!':'J','1':'j',\
        '@':'I','2':'i','#':'H','3':'h','$':'G','4':'g',\
        '%':'F','5':'f','^':'E','6':'e','&':'D','7':'d',\
        '*':'C','8':'c','(':'B','9':'b',')':'A','0':'a',\
        ':':',',',':':','?':'.','.':'?','<':'>','>':'<',\
        "'":'"','"':"'",'+':'-','-':'+','=':';',';':'=',\
        '{':'[','[':'{','}':']',']':'}',' ':' '}


# runs the program
main()