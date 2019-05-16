# DATA FILE NAME
data_notesHit = 'data_notesHit.tsv'
# NOTE: 1159 TOTAL notes
# NOTE: Current Order, lowest to highest score = 10,11,7,6,2,14,13,3,9,5,15,8,12,4,1,16

windowWidth = 1200

set grid
set key right
set key invert
set key samplen (windowWidth * 0.11083333333)

set style data histograms
set style histogram rowstacked
set boxwidth 0.5
set style fill solid 0.5 border lt 0

set xtic (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16)
set ytic (100,200,300,400,500,600,700,800,900,1000,1100,1200)
set yrange [0:1600]
set xrange [0:17]
set xlabel offset 0,-0.6 "Participants" font "Calibri,14"
set ylabel "Total Amount Of Notes Hit" font "Calibri,14"

set terminal qt size windowWidth,600

set terminal qt 0 title 'Note Accuracy' position 0,10
set title "Note Accuracy" font "Times-Roman, 14"
plot data_notesHit		using 2 title "Rock n' Roll All Nite" lt rgb "#000000",\
	 ''					using 3 title "Barracuda" lt rgb "#171919",\
	 ''					using 4 title "Paint It Black" lt rgb "#363C3C",\
	 ''					using 5 title "My Name Is Jonas" lt rgb "#555E5E",\
	 ''					using 6 title "Rock You Like A Hurricane" lt rgb "#8D9D9D",\
	 ''					using 7 title "The Metal" lt rgb "#A8BBBB",\
	 ''					using 8 title "Cult of Personality" lt rgb "#C8DCDC",\
	 ''					using 9 title "Cliffs of Dover" lt rgb "#E7FFFE",\
	 ''					using 0:($2 * 0.5):2 with labels notitle,\
	 ''					using 0:($2 + ($3 * 0.5)):3 with labels notitle,\
	 ''					using 0:($2 + $3 + ($4 * 0.5)):4 with labels notitle,\
	 ''					using 0:($2 + $3 + $4 + ($5 * 0.5)):5 with labels notitle,\
	 ''					using 0:($2 + $3 + $4 + $5 +($6 * 0.5)):6 with labels notitle,\
	 ''					using 0:($2 + $3 + $4 + $5 + $6 + ($7 * 0.5)):7 with labels notitle,\
	 ''					using 0:($2 + $3 + $4 + $5 + $6 + $7 + ($8 * 0.5)):8 with labels notitle,\
	 ''					using 0:($2 + $3 + $4 + $5 + $6 + $7 + $8 + ($9 * 0.5)):9 with labels notitle,\
	 ''					using 0:($2 + $3 + $4 + $5 + $6 + $7 + $8 + $9 + 25):10 with labels notitle