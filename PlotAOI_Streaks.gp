reset
clear

data_visitDuration = 'M_TotalVisitDurationStreaks.tsv'
data_visitCount = 'M_VisitCountStreaks.tsv'
data_fixationCount = 'M_FixationCountStreaks.tsv'

set grid
set key right
set key invert

set style data histograms
set style histogram rowstacked
set boxwidth 0.5
set style fill solid 0.5 border lt 0

set xtic (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16)
#set ytic ("0\%%" 0, "10\%%" 10, "20\%%" 20, "30\%%" 30, "40\%%" 40, "50\%%" 50, "60\%%" 60, "70\%%" 70, "80\%%" 80, "90\%%" 90, "100\%%" 100)
set yrange [0:125]
set xrange [0:17]
set xlabel offset 0,-0.6 "Participant ID" font "Calibri,14"
set ylabel "Percentage  of  Total  Amount" font "Calibri,14"

set terminal qt size 600,600

set terminal qt 0 title 'Visit Duration (Streaks)' position 0,10
set title "Visit Duration (Streaks)" font "Times-Roman, 14"
plot data_visitDuration using 2 title "Bottom Region" lt rgb "#ffaa00",\
	 ''					using 3 title "Middle-Bottom Region" lt rgb "#91e3ff",\
	 ''					using 4 title "Middle-Top Region" lt rgb "#00a5ff",\
	 ''					using 5 title "Top-Bottom Region" lt rgb "#ff9e9e",\
	 ''					using 6 title "Top-Top Region" lt rgb "#ff0000",\
#	 ''					using 0:($2 * 0.5):2 with labels notitle,\
#	 ''					using 0:($2 + ($3 * 0.5)):3 with labels notitle,\
#	 ''					using 0:($2 + $3 + ($4 * 0.5)):4 with labels notitle,\
#	 ''					using 0:($2 + $3 + $4 + ($5 * 0.5)):5 with labels notitle,\
#	 ''					using 0:($2 + $3 + $4 + $5 + ($6 * 0.5)):6 with labels notitle

set terminal qt 1 title 'Visit Count (Streaks)' position 600,10
set title "Visit Count (Streaks)" font "Times-Roman, 14"
plot data_visitCount	using 2 title "Bottom Region" lt rgb "#ffaa00",\
	 ''					using 3 title "Middle-Bottom Region" lt rgb "#91e3ff",\
	 ''					using 4 title "Middle-Top Region" lt rgb "#00a5ff",\
	 ''					using 5 title "Top-Bottom Region" lt rgb "#ff9e9e",\
	 ''					using 6 title "Top-Top Region" lt rgb "#ff0000",\
#	 ''					using 0:($2 * 0.5):2 with labels notitle,\
#	 ''					using 0:($2 + ($3 * 0.5)):3 with labels notitle,\
#	 ''					using 0:($2 + $3 + ($4 * 0.5)):4 with labels notitle,\
#	 ''					using 0:($2 + $3 + $4 + ($5 * 0.5)):5 with labels notitle,\
#	 ''					using 0:($2 + $3 + $4 + $5 + ($6 * 0.5)):6 with labels notitle
	
set terminal qt 2 title 'Fixation Count (Streaks)' position 1200,10
set title "Fixation Duration (Streaks)" font "Times-Roman, 14"
plot data_fixationCount	using 2 title "Bottom Region" lt rgb "#ffaa00",\
	 ''					using 3 title "Middle-Bottom Region" lt rgb "#91e3ff",\
	 ''					using 4 title "Middle-Top Region" lt rgb "#00a5ff",\
	 ''					using 5 title "Top-Bottom Region" lt rgb "#ff9e9e",\
	 ''					using 6 title "Top-Top Region" lt rgb "#ff0000",\
#	 ''					using 0:($2 * 0.5):2 with labels notitle,\
#	 ''					using 0:($2 + ($3 * 0.5)):3 with labels notitle,\
#	 ''					using 0:($2 + $3 + ($4 * 0.5)):4 with labels notitle,\
#	 ''					using 0:($2 + $3 + $4 + ($5 * 0.5)):5 with labels notitle,\
#	 ''					using 0:($2 + $3 + $4 + $5 + ($6 * 0.5)):6 with labels notitle