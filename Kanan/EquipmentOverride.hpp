#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <string>

#include <FunctionHook.hpp>

#include "Mabinogi.hpp"
#include "Mod.hpp"

namespace kanan {
    class EquipmentOverride : public Mod {
    public:
        EquipmentOverride();
        virtual ~EquipmentOverride();

        void onUI() override;

    private:
        struct OverrideInfo {
            std::string name;

            bool isOverridingColor;
            std::array<float, 4> color1;
            std::array<float, 4> color2;
            std::array<float, 4> color3;

            bool isOverridingItem;
            uint32_t itemID;
        };

        std::array<OverrideInfo, 19> m_equipmentOverrides;
        std::unique_ptr<FunctionHook> m_setEquipmentInfoHook;

        static void __fastcall hookedSetEquipmentInfo(CEquipment* equipment, uint32_t EDX, int inventoryID, int itemID, int a4, int a5, uint32_t* color, int a7, int* a8, int a9, int a10, int* a11);
    };
}