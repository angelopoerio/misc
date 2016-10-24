import glob

'''
	Get oom_scores of running processes - Angelo Poerio <angelo.poerio@gmail.com>
        The higher the oom_score is the more the process will risk to be killed!
	Learn more with: man proc
'''

def get_oom_procs():
    oom_procs = []
    for proc_path in glob.glob("/proc/[0-9]*"):
        row = {}
        try:
            with open(proc_path + '/cmdline') as cmd_fd:
                cmdline = cmd_fd.read().replace('\0','')
                if not cmdline: # skip empty cmdline
                   continue
                row['cmdline'] = cmdline
            with open(proc_path + '/oom_score') as score_fd:
                row['oom_score'] = int(score_fd.read())
            with open(proc_path + '/oom_score_adj') as adj_fd:
                row['oom_score_adj'] = int(adj_fd.read())
        except Exception as ex:
            pass # ignore
        oom_procs.append(row)
    return oom_procs

def main():
    oom_list = sorted(get_oom_procs(), key=lambda entry:entry['oom_score'], reverse=True)
    print "%100s %20s %20s" % ("CMD", "OOM_SCORE", "OOM_SCORE_ADJ")
    for proc in oom_list:
         print "%100s %20s %20s" % (proc['cmdline'], proc['oom_score'], proc['oom_score_adj'])

if __name__ == '__main__':
	main()
