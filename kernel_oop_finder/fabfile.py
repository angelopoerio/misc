from fabric.api import *
'''
Look for kernel oops on remote systems! - Angelo Poerio <angelo.poerio@gmail.com>
'''

PEM = 'key.pem' # change with your pem to access the systems

def do_grep(s):
    env.key_filename=[PEM]
    with settings(warn_only=True):
        run("dmesg|egrep -i 'call trace' -A 10") # print 10 lines of call stack 

@hosts('dummyhost1', 'dummyhost2') # changes to your needs
@parallel
def kernel_oop():
    do_grep()

