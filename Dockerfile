FROM python:3.10.3-bullseye

# Install required packages
RUN apt-get update && apt-get install -y --no-install-recommends \
    automake \
    build-essential \
    bzip2 \
    curl \
    doxygen \
    g++ \
    gcc \
    git \
    libboost-dev \
    libboost-thread-dev \
    libclang-dev \
    libntl-dev \
    libsodium-dev \
    libcrypto++-dev \
    libgmp3-dev \
    libssl-dev \
    libtool \
    m4 \
    texinfo \
    make \
    patch \
    python \
    clang-11 \
    vim \
    wget \
    yasm \
    gdb \
    valgrind \
    zip \
    nano \
    net-tools \
    && rm -rf /var/lib/apt/lists/*

# SCALE-MAMBA

WORKDIR /SMPC
ADD ./SCALE-MAMBA/install_dependencies.sh .
RUN ["bash", "install_dependencies.sh"]

COPY ./SCALE-MAMBA /SMPC/SCALE-MAMBA

ADD ./SCALE-MAMBA/source /SMPC/source
ADD ./SCALE-MAMBA/install.sh .
RUN ["bash", "install.sh"]

ADD ./SCALE-MAMBA/install_wasm.sh .
RUN ["bash", "install_wasm.sh"]

COPY ./algorithms/scale-mamba /SMPC/SCALE-MAMBA/Marketplace/

ENV PATH ~/.cargo/bin/:${PATH}

# MP-SPDZ

WORKDIR /SMPC/MP-SPDZ

COPY --from=initc3/mpir:55fe6a9 /usr/local/mpir/include/* /usr/local/include/
COPY --from=initc3/mpir:55fe6a9 /usr/local/mpir/lib/* /usr/local/lib/
COPY --from=initc3/mpir:55fe6a9 /usr/local/mpir/share/info/* /usr/local/share/info/

RUN pip install --upgrade pip ipython

COPY ./MP-SPDZ /SMPC/MP-SPDZ

COPY ./algorithms/mp-spdz /SMPC/MP-SPDZ/Programs/Marketplace/

ARG arch=native
ARG cxx=clang++-11
ARG use_ntl=0
ARG prep_dir="Player-Data"
ARG ssl_dir="Player-Data"

RUN echo "ARCH = -march=${arch}" >> CONFIG.mine \
        && echo "CXX = ${cxx}" >> CONFIG.mine \
        && echo "USE_NTL = ${use_ntl}" >> CONFIG.mine \
        && echo "MY_CFLAGS += -I/usr/local/include" >> CONFIG.mine \
        && echo "MY_LDLIBS += -Wl,-rpath -Wl,/usr/local/lib -L/usr/local/lib" \
            >> CONFIG.mine \
        && mkdir -p $prep_dir $ssl_dir \
        && echo "PREP_DIR = '-DPREP_DIR=\"${prep_dir}/\"'" >> CONFIG.mine \
        && echo "SSL_DIR = '-DSSL_DIR=\"${ssl_dir}/\"'" >> CONFIG.mine


# ssl keys
ARG cryptoplayers=0
ENV PLAYERS ${cryptoplayers}
RUN ./Scripts/setup-ssl.sh ${cryptoplayers} ${ssl_dir}

CMD ["/bin/bash"]

