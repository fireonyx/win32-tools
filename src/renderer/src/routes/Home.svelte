<script lang="ts">
	import Icon from "@iconify/svelte";
    import Logo from "../components/Logo.svelte";

    let canvas: HTMLCanvasElement;
    let attached = false;
    let ctx: CanvasRenderingContext2D;

	setTimeout(() => {
		ctx = canvas.getContext("2d");
		attached = true;

		ctx.fillStyle = "#000";
		ctx.fillRect(0, 0, canvas.width, canvas.height);
	}, 200);
</script>

<section class="shield">
	<section class="view">
		<canvas class="emulatorView" bind:this={canvas}></canvas>
		<div class="logo">
			<svg width="100" height="100" viewBox="0 0 100 100" fill="none" xmlns="http://www.w3.org/2000/svg">
				<path d="M32.7574 34H16.4142C15.5233 34 15.0771 35.0771 15.7071 35.7071L28.5858 48.5858C29.3668 49.3668 29.3668 50.6332 28.5858 51.4142L1.70711 78.2929C1.07714 78.9229 1.52331 80 2.41421 80H18.7574C19.553 80 20.3161 79.6839 20.8787 79.1213L50 50L34.8787 34.8787C34.3161 34.3161 33.553 34 32.7574 34Z" fill="currentcolor"/>
				<path d="M67.6569 66H83.5858C84.4767 66 84.9229 64.9229 84.2929 64.2929L71.4142 51.4142C70.6332 50.6332 70.6332 49.3668 71.4142 48.5858L98.2929 21.7071C98.9229 21.0771 98.4767 20 97.5858 20H81.6569C80.596 20 79.5786 20.4214 78.8284 21.1716L50 50L64.8284 64.8284C65.5786 65.5786 66.596 66 67.6569 66Z" fill="currentcolor"/>
			</svg>
		</div>
	</section>

	<section class="emulator-sidebar">
		<span>EMULATOR POWER AND BOOT CONTROL</span>
		<div>
			<button>
				<Icon icon="mdi:power" />
			</button>

			<button>
				<Icon icon="mdi:power-cycle" />
			</button>

			<button>
				<Icon icon="mdi:power-plug" />
			</button>
		</div>

		<hr />

		<span>EMULATOR STATS</span>
		<div>
			<div class="stats">
				<div class="stat">
				<span class="icon">
					<Icon icon="mdi:cpu-32-bit" />
				</span>
					<span class="value">0% speed</span>
				</div>

				<div class="stat">
				<span class="icon">
					<Icon icon="mdi:memory" />
				</span>
					<span class="value">0% memory used</span>
				</div>

				<div class="stat">
				<span class="icon">
					<Icon icon="mdi:clock" />
				</span>
					<span class="value">0 hz clock speed</span>
				</div>
			</div>
		</div>
	</section>
</section>

<style lang="scss">
@import "../Config.scss";

.shield {
  display: flex;
  flex-direction: row;

  .view {
	position: relative;

	canvas {
	  border: 1px solid $d4;
	  width: calc(100vw - 60px - 10px - 320px - 10px);
	  border-radius: 4px;
	  height: calc((100vw - 60px - 10px - 320px - 10px) * 9 / 16);
	  max-height: calc(100vh - 60px - 10px - 10px);
	  max-width: calc((100vh - 60px - 10px - 10px) * 16 / 9);
	}

	.logo {
	  position: absolute;
	  top: 50%;
	  left: 50%;
	  transform: translate(-50%, -50%);
	  width: 30%;
	  display: flex;
	  align-items: center;
	  justify-content: center;
	  height: 30%;

	  svg {
		width: 100%;
		height: 100%;
        animation: pulseLogo 1s infinite;
		color: $accent;
	  }
	}

	@keyframes pulseLogo {
	  0% {
		filter: grayscale(100%) brightness(0.2);
	  }
	  50% {
		filter: grayscale(0%) brightness(1);
	  }
	  100% {
		filter: grayscale(100%) brightness(0.2);
	  }
	}
  }

  .emulator-sidebar {
	display: flex;
	flex-direction: column;
	gap: 5px;
	padding: 10px;
	width: 100%;

	span {
      font-size: 9px;
      font-family: "Cascadia Mono";
	  color: $f2;
    }

	hr {
	  border: none;
	  background: $d2;
	  height: 1px;
	  width: 100%;
	  margin: 10px 0;
	}

	& > div {
	  display: flex;
	  flex-direction: row;
	  gap: 5px;

	  .stats {
		display: flex;
		flex-direction: column;
		gap: 4px;
	  }

	  .stat {
		display: flex;
		align-items: center;
		gap: 10px;

		.icon {
		  display: flex;
		  align-items: center;
		  justify-content: center;
		  width: 20px;
		  height: 20px;
		  border-radius: 4px;
		  font-size: 16px;
		  background: $d3;
		  color: $accent;
        }
      }

      button {
        display: flex;
        align-items: center;
        justify-content: center;
        width: 40px;
        height: 40px;
        border-radius: 4px;
        border: none;
        background: transparent;
        cursor: pointer;
        color: $f2;
		transition: $to1;
		font-size: 16px;

		&:hover {
			background: $d4;
			color: $accent;
		}
      }
	}
  }
}
</style>