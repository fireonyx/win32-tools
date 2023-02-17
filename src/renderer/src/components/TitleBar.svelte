<script lang="ts">
import Icon from '@iconify/svelte';
</script>

<div class="title-bar">
    <section class="meta">
        <div class="icon">
            <svg width="100" height="100" viewBox="0 0 100 100" fill="none" xmlns="http://www.w3.org/2000/svg">
                <path d="M32.7574 34H16.4142C15.5233 34 15.0771 35.0771 15.7071 35.7071L28.5858 48.5858C29.3668 49.3668 29.3668 50.6332 28.5858 51.4142L1.70711 78.2929C1.07714 78.9229 1.52331 80 2.41421 80H18.7574C19.553 80 20.3161 79.6839 20.8787 79.1213L50 50L34.8787 34.8787C34.3161 34.3161 33.553 34 32.7574 34Z" fill="currentcolor"/>
                <path d="M67.6569 66H83.5858C84.4767 66 84.9229 64.9229 84.2929 64.2929L71.4142 51.4142C70.6332 50.6332 70.6332 49.3668 71.4142 48.5858L98.2929 21.7071C98.9229 21.0771 98.4767 20 97.5858 20H81.6569C80.596 20 79.5786 20.4214 78.8284 21.1716L50 50L64.8284 64.8284C65.5786 65.5786 66.596 66 67.6569 66Z" fill="currentcolor"/>
            </svg>
        </div>

        <span>FireStone Emulator</span>
    </section>

    <section class="command">
        <input type="text" placeholder="Enter command or memory block address" />
        <button>
            <span>
                <Icon icon="fluent:play-16-regular" />
            </span>
        </button>
    </section>

    <section class="control">
        <button>
            <span>
                <Icon style="font-size: 17px;" icon="fluent:subtract-20-regular" />
            </span>
        </button>

        <button>
            <span>
                <Icon icon="fluent:maximize-16-regular" />
            </span>
        </button>

        <button>
            <span>
                <Icon icon="fluent:dismiss-16-regular" />
            </span>
        </button>
    </section>
</div>

<style lang="scss">
@import "../Config";

.title-bar {
    background: $l2;
    display: flex;
    width: 100vw;
    height: 50px;
    -webkit-app-region: drag;
    flex-direction: row;
    align-items: center;
    justify-content: space-between;

    section.meta {
        display: flex;
        flex-direction: row;
        align-items: center;
        gap: 20px;
        padding-left: 20px;
        color: $f1;
        font-family: "Cascadia Mono";
        font-size: 11px;

        .icon {
            font-size: 16px;
            display: flex;
            align-items: center;
            justify-content: center;

            svg {
                width: 25px;
            }
        }

        span {
            color: $f2;
        }
    }

    section.control {
        display: flex;
        flex-direction: row;
        -webkit-app-region: no-drag;
        height: 100%;

        button {
            background: transparent;
            border: none;
            -webkit-app-region: no-drag;
            width: 50px;
            height: 100%;
            display: flex;
            align-items: center;
            justify-content: center;
            color: #fff;
            font-size: 16px;
            position: relative;

            &:before {
                content: "";
                display: flex;
                position: absolute;
                width: 35px;
                height: 35px;
                transition: $ti1;
                border-radius: 4px;
            }

            span {
                position: absolute;
                padding-top: 3px;
            }

            &:hover {
                &:before {
                    background: $l1;
                    transition: $to1;
                }

                &:nth-child(3) {
                    color: $l2;

                    &:before {
                        background: $critical !important;
                    }
                }
            }
        }
    }

    section.command {
        display: flex;
        flex-direction: row;
        align-items: center;
        gap: 0px;
        justify-content: space-between;
        height: 50px;
        -webkit-app-region: no-drag;

        input {
            width: 500px;
            display: flex;
            height: 35px;
            background: $d4;
            border: 0px solid #111;
            border-radius: 4px;
            padding: 0 20px;
            transition: $ti1;
            -webkit-app-region: no-drag;
            outline: none;
            border-bottom: 2px solid #333;
            color: $f1;

            &:focus {
                border-bottom: 2px solid $accent;
                transition: $to1;
            }
        }

        button {
            background: transparent;
            border: none;
            -webkit-app-region: no-drag;
            width: 50px;
            height: 100%;
            display: flex;
            align-items: center;
            justify-content: center;
            color: $accent;
            font-size: 16px;
            position: relative;

            & > span {
                padding-right: 2px;
            }

            &:before {
                content: "";
                display: flex;
                position: absolute;
                width: 35px;
                height: 35px;
                transition: $ti1;
                border-radius: 4px;
            }

            span {
                position: absolute;
                padding-top: 3px;
            }

            &:hover {
                &:before {
                    background: $l1;
                    transition: $to1;
                }
            }
        }
    }
}
</style>