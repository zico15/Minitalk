import random
import sys
import os

if __name__ == "__main__":
    av = sys.argv[1:]
    for numero in range(int(av[0])):
        print("a", end="")
    print("ommon Instructions•Your project must be written in C.•Your project must be written in accordance with the Norm.  If you have bonusfiles/functions, they are included in the norm check and you will receive a0if thereis a norm error inside.•Your functions should not quit unexpectedly (segmentation fault, bus error, doublefree, etc) apart from undefined behaviors.  If this happens, your project will beconsidered non functional and will receive a0during the evaluation.•All heap allocated memory space must be properly freed when necessary. No leakswill be tolerated.•If the subject requires it, you must submit aMakefilewhich will compile yoursource files to the required output with the flags-Wall,-Wextraand-Werror, usecc, and your Makefile must not relink.•YourMakefilemust at least contain the rules$(NAME),all,clean,fcleanandre.•To turn in bonuses to your project, you must include a rulebonusto your Makefile,which will add all the various headers, librairies or functions that are forbidden onthe main part of the project. Bonuses must be in a different file_bonus.{c/h}ifthe subject does not specify anything else. Mandatory and bonus part evaluationis done separately.•If your project allows you to use yourlibft, you must copy its sources and itsassociatedMakefilein alibftfolder with its associated Makefile. Your project’sMakefilemust compile the library by using itsMakefile, then compile the project.•We encourage you to create test programs for your project even though this workwon’t have to be submitted and won’t be graded. It will give you a chanceto easily test your work and your peers’ work. You will find those tests especiallyuseful during your defence. Indeed, during defence, you are free to use your testsand/or the tests of the peer you are evaluating.•Submit your work to your assigned git repository. Only the work in the git reposi-tory will be graded. If Deepthought is assigned to grade your work, it will be done")
