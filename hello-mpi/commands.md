# Compile program
mpic++ -o hello-mpi hello-mpi.cpp

# Run program (with any arbitrary arg(s) for example of error) and save results to output.txt
## Good output (if no other actual process error occurs)
mpirun hello-mpi | tee output.txt
## Bad output
mpirun hello-mpi arg | tee output.txt
# Ensure all processes from 0 to n-1 are working
cat output.txt | sort -k4,4n | awk '{print NR,$4}' | awk 'BEGIN {error = 0;} { if (NR - 1 != $2) error = 1; } END { if (error == 0) { print "SUCCESS"; } else { print "ERROR: a process encountered an issue..." }}'
