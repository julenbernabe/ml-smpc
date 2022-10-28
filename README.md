# ML Algorithms over SMPC

This repository contains the implementation of Machine Learning algorithms over two SMPC frameworks:

- SCALE-MAMBA
- MP-SPDZ

These implementations can be seen [here](algorithms). The repository also contains versions of both frameworks, and a Dockerfile to deploy a Docker image containing both of them. The `docker-compose.yml` file allows to create a container running both frameworks simultaneously, with the implemented algorithms added. Note that the framework version used may not be updated. You can check the latest versions referring to [the SCALE-MAMBA GitHub repository](https://github.com/KULeuven-COSIC/SCALE-MAMBA) and [the MP-SPDZ GitHub repository](https://github.com/data61/MP-SPDZ).

In order to test the algorithms, go through the following steps:

1. Run

```bash
./build.sh
```

in order to build the Docker image.
2. Run

```bash
./deploy.sh
```

in order to deploy the Docker container running the previously built image.
3. Load the Iris Database data for players running

```bash
./load-data.sh
```

It is important that you have installed `pandas` Python module. Otherwise, the above command will result in an error.
4. Enter the Docker container in order to run the executions

```bash
docker exec -it smpc-client bash
```

You will enter in a directory called `SMPC`, `cd` to `MP-SPDZ` or `SCALE-MAMBA` to run an algorithm.
5. Refer to [the SCALE-MAMBA GitHub repository](https://github.com/KULeuven-COSIC/SCALE-MAMBA) and [the MP-SPDZ GitHub repository](https://github.com/data61/MP-SPDZ) to see how to run the algorithms.

You now are done!
