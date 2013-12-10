# gcc -o stringkernelTEST stringkerneltest.c suffix_tree.c
# gcc -o stringkernelTRAIN stringkerneltrain.c suffix_tree.c
# ./stringkernelTRAIN >traindata
# ./stringkernelTEST >testdata
for TESTSIZE in 1 10 20 50
do
	for VARIABLE in 1 2 3 4 5 6 7 8 9 10
	do
			gcc -o stringkernelnew stringkernelnew.c suffix_tree.c
			./stringkernelnew 50 $TESTSIZE
			./svm-train traindata
			./svm-predict testdata traindata.model new >>output/output_50_$TESTSIZE
	done
done