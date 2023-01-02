if(NOT TARGET event-modules)
    include(FetchContent)

    FetchContent_Declare(
            event-modules
            GIT_REPOSITORY https://github.com/PolymorphEngine/event-modules.git
            GIT_TAG dev
    )

    FetchContent_MakeAvailable(event-modules)
endif()