	cd UFMS/
	git pull
	git add .
	git commit -m "Horas: $(date +%H:%M:%S) - $(date +%a), dia $(date +%d) de $(date +%b) de $(date +%Y)"
	git push -u origin master
