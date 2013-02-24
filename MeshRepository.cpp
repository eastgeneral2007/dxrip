﻿#include "MeshRepository.h"

namespace com { namespace github { namespace kbinani {

    MeshRepository *MeshRepository::Instance() {
        static MeshRepository instance;
        return &instance;
    }

    void MeshRepository::Register(const MeshDescriptor &descriptor, const std::string &contentsHash) {
        if (!Exists(descriptor)) {
            repository.insert(std::make_pair(descriptor.Hash(), std::make_pair(descriptor, contentsHash)));
        }
    }

    bool MeshRepository::Exists(const MeshDescriptor &descriptor) {
        return repository.find(descriptor.Hash()) != repository.end();
    }

} } }
