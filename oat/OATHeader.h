#pragma once

namespace Art {
    enum InstructionSet {
        kNone,
        kArm,
        kArm64,
        kThumb2,
        kX86,
        kX86_64,
        kMips,
        kMips64
    };

#pragma pack(4)

    class OATHeader {
    public:
        OATHeader() { };

        ~OATHeader() { };

        static const uint8_t kOatMagic[4];//4
        static const uint8_t kOatVersion[4];//8

        //static constexpr const char* kImageLocationKey = "image-location";
        //static constexpr const char* kDex2OatCmdLineKey = "dex2oat-cmdline";
        //static constexpr const char* kDex2OatHostKey = "dex2oat-host";
        //static constexpr const char* kPicKey = "pic";

        bool IsValid() const;

        const char *GetMagic() const;

        uint32_t GetChecksum() const;

        uint32_t GetDexFileCount() const {
            return dex_file_count_;
        }

        uint32_t GetExecutableOffset() const {
            return executable_offset_;
        }

        uint32_t GetKeyValueStoreSize() const {
            return key_value_store_size_;
        }

    private:
        friend class OATParser;

        uint8_t magic_[4];//12
        uint8_t version_[4];//16
        uint32_t adler32_checksum_;//20

        InstructionSet instruction_set_;//24
        uint32_t instruction_set_features_bitmap_;//28
        uint32_t dex_file_count_;
        uint32_t executable_offset_;
        uint32_t interpreter_to_interpreter_bridge_offset_;
        uint32_t interpreter_to_compiled_code_bridge_offset_;
        uint32_t jni_dlsym_lookup_offset_;
        uint32_t quick_generic_jni_trampoline_offset_;
        uint32_t quick_imt_conflict_trampoline_offset_;
        uint32_t quick_resolution_trampoline_offset_;
        uint32_t quick_to_interpreter_bridge_offset_; //64

        // The amount that the image this oat is associated with has been patched.
        int32_t image_patch_delta_;//68
//      uint32_t extra1; // for sumsung
//      uint32_t extra2; // for sumsung
//      uint32_t extra3; // for sumsung
        uint32_t image_file_location_oat_checksum_;//72
        uint32_t image_file_location_oat_data_begin_;//76

        uint32_t key_value_store_size_;//80
        uint8_t key_value_store_[0];  // note variable width data at end

        //DISALLOW_COPY_AND_ASSIGN(OATHeader);
    };

#pragma pack()

}

