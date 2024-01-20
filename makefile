buildcpp:
	docker compose -f docker-compose_cpp.yaml build

buildgo:
	docker compose -f docker-compose_go.yaml build

upcpp:
	docker compose -f docker-compose_cpp.yaml up -d

upgo:
	docker compose -f docker-compose_go.yaml up -d

debugcpp:
	docker compose -f docker-compose_cpp.yaml exec test_leetcode_cpp /bin/bash

debuggo:
	docker compose -f docker-compose_go.yaml exec test_leetcode_go /bin/bash

downcpp:
	docker compose -f docker-compose_cpp.yaml down

downgo:
	docker compose -f docker-compose_go.yaml down

clean:
	docker image prune -a; docker system prune -a --volumes;
