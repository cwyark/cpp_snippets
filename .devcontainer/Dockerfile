FROM ubuntu:focal

ENV DEBIAN_FRONTEND=noninteractive \
  LANG=en_US.UTF-8 \
  LANGUAGE=en_US.UTF-8 \
  LC_ALL=en_US.UTF-8 

# Install build-essential
RUN apt-get update && \
  apt-get install -y \
  build-essential \
  git \
  curl \
  ca-certificates \
  zsh \
  --no-install-recommends && \
  apt-get clean && \
  rm -rf /var/lib/apt/lists/*

USER ubuntu
