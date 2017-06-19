package main

/* Retrieve system metrics by a simple Http interface
   Run as a background process: nohup ./HttpStats  &
   TODO: daemonize the service!
   Author: Angelo Poerio <angelo.poerio@gmail.com> */

import (
	"fmt"
	"log"
	"net/http"
	"os/exec"
)

func runCmd(cmd string) string {
	out, err := exec.Command("bash", "-c", cmd).Output() /* change the invoked shell according to your system */

	if err != nil {
		return fmt.Sprintf("%s", err)
	}

	return string(out[:])
}

func ps(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, runCmd("ps aux"))
}

func uptime(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, runCmd("uptime"))
}

func tcpStats(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, runCmd("ss -tnp"))
}

func udpStats(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, runCmd("ss -unp"))
}

func vmStat(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, runCmd("vmstat"))
}

func main() {
	http.HandleFunc("/tcpStats", tcpStats)
	http.HandleFunc("/udpStats", udpStats)
	http.HandleFunc("/ps", ps)
	http.HandleFunc("/vmstat", vmStat)
	http.HandleFunc("/uptime", uptime)
	log.Fatal(http.ListenAndServe(":9000", nil)) /* change as you need */
}
