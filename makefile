image: image.c
	gcc -o image image.c
	
run: image
	./image
	
convert: image.ppm
	convert image.ppm image.jpg

clean:
	rm image.ppm
	rm image.jpg
	rm image