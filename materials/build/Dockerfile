FROM alpine:3.20

RUN apk --no-cache --upgrade add \
    git \
    git-lfs \
    curl \
    jq \
    bash \
    build-base \
    python3 \
    valgrind \
    cppcheck \
    alpine-sdk \
    pcre-dev \
    pcre2 \
    clang18-extra-tools && \
    ln -s /usr/lib/llvm18/bin/clang-format /usr/bin/clang-format 

RUN mkdir /test 

COPY . /project
COPY materials/build/scripts /project/ci-scripts
COPY materials/build/scripts /project/tests
COPY materials/linters /project/tests/linters

WORKDIR "/project"

ENTRYPOINT ["/bin/bash","ci-scripts/test.sh"]
