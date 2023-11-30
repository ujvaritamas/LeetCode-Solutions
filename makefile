build:
	docker build -t test_cpp .
run:
	docker run -d --name test_cpp_cont -v .:/code test_cpp

debug:
	docker exec -it test_cpp_cont /bin/bash

clean:
	docker kill test_cpp_cont
	docker image rm -f test_cpp
	docker container rm -f test_cpp
	docker image prune -a; docker system prune -a --volumes;