# Introduction
This is a simple experiment to better understand the usage of the [perf tool] (https://perf.wiki.kernel.org/index.php/Main_Page)

# Experiment setup
* redis 3.2.3
* a test python script that writes 10^6 keys
* command used to profile everything: **perf record -p $(pidof redis-server)**

# Results
* One of the redis-server functions with the biggest overhead is **dictFind()** (you also have malloc() but it is libc-related). [.] are userl-space functions, [k] are kernel-space functions
* ![Perf report](screenshots/perf_report.png?raw=true "Perf report")
* it is defined in **src/dict.c at line 492**
* 
```
dictEntry *dictFind(dict *d, const void *key)
{
    dictEntry *he;
    unsigned int h, idx, table;

    if (d->ht[0].used + d->ht[1].used == 0) return NULL; /* dict is empty */
    if (dictIsRehashing(d)) _dictRehashStep(d);
    h = dictHashKey(d, key);
    for (table = 0; table <= 1; table++) {
        idx = h & d->ht[table].sizemask;
        he = d->ht[table].table[idx];
        while(he) {
            if (key==he->key || dictCompareKeys(d, key, he->key))
                return he;
            he = he->next;
        }
        if (!dictIsRehashing(d)) return NULL;
    }
    return NULL;
}
```
* This can be the beginning to understand what a production service is doing
* Results can change on a different system with a different workload!

