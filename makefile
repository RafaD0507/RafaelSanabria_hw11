phase.png: tray.txt
	python RS_graph.py
	rm tray.txt rs.rs

tray.txt: rs.rs
	./rs.rs > tray.txt

rs.rs:
	c++ RS_gravity.cpp -o rs.rs

