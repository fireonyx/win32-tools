<script lang="ts">
import Icon from '@iconify/svelte';
</script>

<div class="title-bar">
    <section class="meta">
        <div class="icon">
            A
        </div>

        <span>FireStone Emulator</span>
    </section>

    <section class="command">

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
                width: 90%;
                height: 90%;
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
}
</style>