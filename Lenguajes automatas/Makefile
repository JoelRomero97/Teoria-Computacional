SOURCEDIRS = automata file grammar gui regular
AUX = DOCS ICON MEDIA Makefile mainFile README LICENSE ChangeLog.txt

all:
	javac *.java
	find . -name "*.class" -o -name "*.java" > OUTYOUTY
	
	jar cmf mainFile JFLAP_With_Source.jar @OUTYOUTY $(AUX)
	rm OUTYOUTY

without-source ws:
	javac *.java
	find . -name "*.class" > OUTYOUTY
	jar cmf mainFile JFLAP.jar @OUTYOUTY $(AUX)
	rm OUTYOUTY


update:
	javac *.java
	find . -name "*.class" -o -name "*.java" > OUTYOUTY
	
	jar uf JFLAP.jar @OUTYOUTY $(AUX)
	rm OUTYOUTY
	
jar:
	find . -name "*.class" -o -name "*.java" > OUTYOUTY
	jar cmf  mainFile JFLAP_With_Source.jar @OUTYOUTY $(AUX)
	rm OUTYOUTY

jar-ws:
	find . -name "*.class" > OUTYOUTY
	jar cmf mainFile JFLAP.jar @OUTYOUTY $(AUX)
	rm OUTYOUTY

clean:
	find $(SOURCEDIRS) \( -name "*.class" -o -name "*~" -o -name ".DS_Store" \) \
		-a -delete
	rm -f JFLAP.jar

